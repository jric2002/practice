# Comandos de configuración para una conexión SSH
## Cliente
Si tienes varias claves SSH, entonces puedes utilizar los siguientes commandos y pegarlos en el archivo `config`, dicho archivo se ubica en `~/.ssh/config`.  
Si el archivo no existe, entonces debes crealo.
```
# GitHub
Host github.com
  Hostname github.com
  PreferredAuthentications publickey
  IdentityFile ~/.ssh/github_key

# GitLab
Host gitlab.com
  Hostname gitlab.com
  PreferredAuthentications publickey
  IdentityFile ~/.ssh/gitlab_key
```

Ahora, si intentas conectarte a un servidor ssh RANDOM, entonces el cliente ssh usará de forma predeterminada la clave ssh que se encuentra en ~/.ssh/id_rsa

Y si tienes varias clave ssh, entonces el cliente ssh intentará probar con cada una de ellas, ya sea: `id_rsa`, `id_dsa`, `id_ecdsa`, `id_ed25519` y otros

También puedes especificar que clave privada quieres usar para autenticación al momento de conectarte, de la siguiente forma: `ssh -i ~/.ssh/clave_privada usuario@127.0.0.1`

## Servidor
Puedes iniciar el servidor ssh con el comando: `sudo service ssh start`  
También puedes usar:
- `sudo service --status-all` : Para ver que servicios estas activos
- `sudo service ssh stop` : Detener el servicio ssh
- `sudo service ssh --full-restart` : Reiniciar el servicio ssh

El servidor ssh tiene sus propias claves privadas y públicas, se encuentran en `/etc/ssh/` con 

### Configuración del servidor ssh
El archivo de configuración se encuentra en `/etc/ssh/sshd_config`  
De forma predeterminada, el servidor tiene habilitado la autenticación por clave pública y por contraseña.  
- Puedes deshabilitar la autenticación para todos los usuarios, de la siguiente manera:
`AuthenticationMethods none`

- En la configuración puedes agregar varios métodos de autenticación extra, por ejemplo:

Ejemplo 1
```
Match User jos
  AuthenticationMethods publickey
```

Ejemplo 2
```
Match User jos,daniel
  AuthenticationMethods password,publickey
```
En el ejemplo 2, el servidor primero verificará si la contraseña es correcta o no. Si la contraseña es correcta entonces verificará si la clave pública se encuentra dentro del archivo `~/.ssh/authorized_keys` del usuario.

En resumen, se agrega una método de autenticación extra.

**Nota**: El servidor respeta el orden de los métodos de autenticación, es decir, que si tienes `password,publickey`, entonces primero usará el método de contraseña, luego el método de publickey.

- Si quieres que un usuario inicie sin contraseña, entonces puedes establecer esta regla:
```
Match User marco
  PermitEmptyPasswords yes
```

**Nota**: `PermitEmptyPasswords` solo funciona si el usuario marco tiene una contraseña vacía.

- Otro caso, es cuanto quieres centralizar los archivos `authorized_keys` en un directorio para que la adminstración de las claves ssh de los usuarios sea más fácil. Por ejemplo, supongamos que tenemos 3 usuarios: jos, miguel, daniel

Lo primero que debes hacer es crear un directorio `authorized_keys` en:
```
sudo mkdir /etc/ssh/authorized_keys
```

Luego, dentro del directorio `authorized_keys` debes que crear una archivo para cada usuario, pero el nombre del archivo debe ser el nombre del usuario.
```
touch /etc/ssh/authorized_keys/jos
touch /etc/ssh/authorized_keys/miguel
touch /etc/ssh/authorized_keys/daniel
```

Ahora, en los archivos `jos`, `miguel`, `daniel`, debes agregar las claves públicas autorizadas, la cuales pueden ser diferentes o no.

### Registros del servidor ssh
Los registros del servidor ssh se guardan en el archivo `auth.log`, el cual se encuentra en: `/var/log/auth.log`.

Debes saber que el nivel de registro es posible cambiarlo. Por defecto esta configurado de el archivo ``/etc/ssh/sshd_config`: `LogLevel INFO`  
Si quieres que guarde más información cambialo a `LogLevel VERBOSE`.

Además, la ubicación y el nombre del archivo de registro varía en función del sistema operativo que uses.

En WSL (Windows Subsystem for Linux) teniendo a Debian como distribución. El registro de los eventos se encarga el servicio `rsyslog`. Entonces, si no encuentras el archivo `auth.log` es porque `rsyslog` no esta activado. Y para activar el servicio `rsyslog`, debes hacer lo siguiente:
```
sudo service rsyslog start
```

## Registro del Sistema
Esto es una respuesta de ChatGPT:

En Linux, los registros del sistema se encuentran generalmente en el directorio `/var/log`. Aquí encontrarás varios archivos de registro que registran diferentes aspectos del sistema y las actividades del usuario. Algunos de los archivos de registro comunes incluyen:

- `/var/log/syslog` o `/var/log/messages`: Registra los mensajes generales del sistema.
- `/var/log/auth.log`: Registra los intentos de inicio de sesión y otras actividades de autenticación.
- `/var/log/kernel.log`: Registra los mensajes del núcleo del sistema.
- `/var/log/secure`: Registra los intentos de autenticación y otras actividades de seguridad (generalmente en sistemas basados en Red Hat).
- `/var/log/dmesg`: Muestra los mensajes del núcleo desde el último arranque del sistema.

Para ver estos registros, puedes usar herramientas como `cat`, `less`, `tail`, `grep` u otros visores de archivos de texto. Por ejemplo, para ver los últimos mensajes del registro del sistema, puedes usar el siguiente comando en la terminal:

```
sudo tail -n 100 /var/log/syslog
```

Este comando mostrará los últimos 100 líneas del archivo `/var/log/syslog`. Recuerda que es posible que necesites permisos de superusuario (`sudo`) para acceder a algunos de estos archivos.
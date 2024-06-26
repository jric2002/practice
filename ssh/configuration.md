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

El servidor ssh tiene sus propias claves privadas y públicas, se encuentran en `/etc/ssh/` con nombres como: `ssh_host_dsa_key`, `ssh_host_rsa_key`.

### Configuración del servidor ssh
El archivo de configuración se encuentra en `/etc/ssh/sshd_config`

Te dejaré un archivo de configuración de configuración en esta misma carpeta, en la cuál solo estará los parámetros que va vienen el archivo de configuración por defecto con las modificaciones hechas a algunos parámetros y algunos parámetros adicionales.

**Nota**: YO USO UNA CONFIGURACIÓN EN LA QUE `AuthenticationMethods none` BLOQUEA TODOS LOS MÉTODOS DE AUTENTICACIÓN, ES POR ELLO QUE NO TENGO DESCOMENTADO LOS PARÁMETROS `PubkeyAuthentication no` y `PasswordAuthentication no`. DEBES TENER EN CUENTA QUE USO `AuthenticationMethods` CON `Match User`, LA RAZÓN LO EXPLICO MAS ADELANTE. SIN EMBARGO, TU PUEDES USAR OTRA CONFIGURACIÓN SI DESEAS, EN LA QUE NO USES `AuthenticationMethods`. ES TU DECISIÓN.

Se recomienda que cambiar el puerto 22 por otro puerto, por lo general suelen usar puertos mayores a 10 000, esto para evitar conflictos con algunos servicios.

Es recomendable crear un usuario pero que este sea parte del grupo sudo, de tal manera que ahora en la configuración del servidor desactivemos el inicio de sesión con el usuario root: `PermitRootLogin no`. Esto lo puedes combinar con `AuthenticationMethods` y `Match User`, más adelante explico cómo funciona.

Casi me olvido, en la configuración también se especifica que tipos de claves publicas acepta el servidor, el parámetro que lo controla es `PubkeyAcceptedAlgorithms`.

De forma predeterminada, el servidor tiene habilitado la autenticación por clave pública y por contraseña.  
- Puedes deshabilitar la autenticación para todos los usuarios, de la siguiente manera:
`AuthenticationMethods none`

**Nota:** Debes tener en cuenta que `AuthenticationMethods` solo controla los métodos de autenticación.

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

Y finalmente, debes editar el archivo `sshd_config`, solo debes agregar esta comando:
```
# Directorio centralizado de claves autorizadas de los usuarios
AuthorizedKeysFile /etc/ssh/authorized_keys/%u
```

**Nota**: Si usas un directorio centralizado de claves autorizadas, entonces si o si debe ser centralizado, ya que en el caso de que tengas una clave en `authorized_keys` pero en la carpeta `$HOME/.ssh/authorized_keys` del USUARIO, entonces NO funcionará, ya que las claves estan centralizadas en el directorio `/etc/ssh/authorized_keys/`

### Registros del servidor ssh
Los registros del servidor ssh se guardan en el archivo `auth.log`, el cual se encuentra en: `/var/log/auth.log`.

Debes saber que el nivel de registro es posible cambiarlo. Por defecto esta configurado de el archivo ``/etc/ssh/sshd_config`: `LogLevel INFO`  
Si quieres que guarde más información cambialo a `LogLevel VERBOSE`.

Además, la ubicación y el nombre del archivo de registro varía en función del sistema operativo que uses.

En WSL (Windows Subsystem for Linux) teniendo a Debian como distribución. El registro de los eventos se encarga el servicio `rsyslog`. Entonces, si no encuentras el archivo `auth.log` es porque `rsyslog` no esta activado. Y para activar el servicio `rsyslog`, debes hacer lo siguiente:
```
sudo service rsyslog start
```

## Conexiones ssh
Si quieres ver los usuarios que estan conectados por ssh, puedes usar el comando: `w` o `who -a`

### Ver ultimas conexiones
Para ver las ultimas conexiones puedes usar el comando: `last`

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

## Descargar y subir archivos o carpetas al servidor ssh
Se suele mas el `scp`.

Para descargar y subir archivos o carpetas a un servidor SSH desde la terminal utilizando `scp` (Secure Copy), puedes seguir estos pasos básicos:

### Usando `scp` (Secure Copy)
Si usas una clave especifica y un puerto diferente, puedes usar los argumentos `-i` y `-p`.

1. **Descargar desde el servidor SSH al local:**

  ```
  scp usuario@servidor_remoto:/ruta/al/archivo_local /ruta/destino/local
  ```

  - `usuario`: Nombre de usuario en el servidor SSH.
  - `servidor_remoto`: Dirección IP o nombre de dominio del servidor SSH.
  - `/ruta/al/archivo_local`: Ruta del archivo en el servidor remoto que quieres descargar.
  - `/ruta/destino/local`: Ruta en tu máquina local donde deseas guardar el archivo.

  Por ejemplo:
  ```
  scp user@example.com:/home/user/file.txt /home/localuser/Documents/
  ```

  Si quieres descargar el archivo del servidor, pero usas un puerto diferente y una clave pública específica, entonces puedes hacerlo de la siguiente manera:

  ```
  scp -i ruta_a_clave_privada -P puerto usuario@servidor:/ruta/remote/archivo /ruta/destino/local
  ```

2. **Subir desde local al servidor SSH:**

  ```
  scp /ruta/al/archivo_local usuario@servidor_remoto:/ruta/destino/remoto
  ```

  - `/ruta/al/archivo_local`: Ruta del archivo en tu máquina local que quieres subir.
  - `usuario`: Nombre de usuario en el servidor SSH.
  - `servidor_remoto`: Dirección IP o nombre de dominio del servidor SSH.
  - `/ruta/destino/remoto`: Ruta en el servidor remoto donde deseas guardar el archivo.

  Por ejemplo:
  ```
  scp /home/localuser/Documents/file.txt user@example.com:/home/user/
  ```

  Si quieres subir el archivo al servidor, pero usas un puerto diferente y una clave pública específica, entonces puedes hacerlo de la siguiente manera:

  ```
  scp -i ruta_a_clave_privada -P puerto ruta_del_archivo usuario@servidor:/ruta/destino/
  ```

### Alternativas a `scp`:

1. **Usar `rsync`:**
   `rsync` es otra herramienta muy útil para transferencias de archivos a través de SSH. Es similar a `scp` pero está optimizado para sincronizar directorios y manejar transferencias de grandes volúmenes de datos de manera más eficiente.

   Ejemplo de uso básico:
   ```
   rsync -avz -e ssh /ruta/local usuario@servidor_remoto:/ruta/remota
   ```

   - `-avz`: Opciones para modo archivo, modo verbose y compresión.
   - `-e ssh`: Especifica que se utiliza SSH como el método de transporte.
   - `/ruta/local`: Ruta del directorio o archivo local que deseas transferir.
   - `usuario@servidor_remoto:/ruta/remota`: Ruta en el servidor remoto donde deseas guardar los archivos.

2. **Montar el sistema de archivos remoto:**
   Puedes montar el sistema de archivos del servidor remoto en tu máquina local utilizando `sshfs` (SSH Filesystem). Esto te permite acceder y manipular archivos remotos como si estuvieran en tu propio sistema de archivos local.

   Ejemplo:
   ```
   sshfs usuario@servidor_remoto:/ruta/remota /ruta/de/montaje/local
   ```

   Esto montará el directorio `/ruta/remota` del servidor remoto en `/ruta/de/montaje/local` de tu máquina local. Luego puedes trabajar con los archivos como si estuvieran localmente.

3. **Utilizar clientes SFTP (FTP seguro):**
   Hay varios clientes gráficos y de línea de comandos que soportan el protocolo SFTP, como `FileZilla`, `WinSCP` (Windows), `Cyberduck` (macOS), y `lftp` (linea de comandos para Linux). Estos permiten una interfaz más amigable para gestionar transferencias de archivos a través de SSH.

Cada opción tiene sus ventajas dependiendo de tus necesidades específicas (velocidad, cantidad de datos, complejidad del directorio, etc.). `scp` es la opción más directa desde la línea de comandos, mientras que `rsync` es ideal para sincronización y manejo avanzado de archivos.
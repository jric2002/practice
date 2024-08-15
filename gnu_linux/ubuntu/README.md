# Cómo agregar espacio de intercambio en Ubuntu 22.04

Toda esta información es un traducción al español de un artículo del sitio web: https://linuxize.com/post/how-to-add-swap-space-on-ubuntu-22-04/

El espacio de intercambio es un espacio en una unidad de disco que se utiliza cuando la cantidad de memoria RAM física está llena. Cuando un sistema Linux se queda sin memoria RAM, mueve las páginas inactivas de la RAM al espacio de intercambio.

El espacio de intercambio puede adoptar la forma de una partición de intercambio dedicada, un archivo de intercambio o una combinación de particiones y archivos. Generalmente, cuando se ejecuta Ubuntu en una máquina virtual, no hay una partición de intercambio y la única opción es crear un archivo de intercambio.

Este artículo lo guiará a través de los pasos para agregar un archivo de intercambio en un sistema Ubuntu 22.04.

## Antes de empezar

El espacio de intercambio no reemplaza a la memoria física. Dado que el espacio de intercambio es una sección de la unidad, tiene un tiempo de acceso más lento que la memoria física. Si su sistema se queda constantemente sin memoria, debe agregar más RAM.

En la mayoría de los casos, el tamaño del archivo de intercambio depende de la RAM física que tenga el sistema Linux:

- Sistemas con **menos de 2 GB de RAM** : el doble de cantidad de RAM.
- Sistemas con **2 a 8 GB de RAM** : el mismo tamaño que la cantidad de RAM.
- Sistemas con **más de 8 GB de RAM** : al menos 4 GB de Swap.

Sólo los usuarios root o con privilegios sudo pueden activar el archivo de intercambio.

Antes de comenzar, siempre es una buena idea comprobar si ya tienes una unidad de intercambio en tu sistema. Puedes hacerlo con el siguiente comando:

```bash
sudo swapon --show
```

Si la salida está vacía, significa que el sistema no tiene un espacio de intercambio configurado. De lo contrario, el comando mostrará una lista de espacios de intercambio configurados.

Otra opción es utilizar el comando `free`:

```bash
free -h
```

El comando imprimirá la información sobre el uso de la memoria del sistema, así como el espacio de intercambio:

```
              total        used        free      shared  buff/cache   available
Mem:          3.8Gi       563Mi       2.8Gi       0.0Ki       516Mi       3.1Gi
Swap:            0B          0B          0B
```

## Creando un archivo de intercambio

En esta guía, crearemos un archivo de intercambio de `4 GB`. Si necesita agregar más o menos espacio de intercambio, reemplácelo con el tamaño de espacio de intercambio requerido.

Antes de crear el archivo, asegúrese de tener suficiente espacio libre en el disco para completar este proceso correctamente. Puede obtener un informe detallado sobre el uso del espacio en disco del sistema con el comando `df`:

```bash
df -h
```

Aquí, el sistema de archivos raíz (`/`) tiene suficiente espacio libre (`53G`) para crear el archivo.

```
Filesystem                         Size  Used Avail Use% Mounted on
tmpfs                              197M  948K  196M   1% /run
/dev/mapper/ubuntu--vg-ubuntu--lv   62G  6.3G   53G  11% /
tmpfs                              982M     0  982M   0% /dev/shm
tmpfs                              5.0M     0  5.0M   0% /run/lock
/dev/sda2                          2.0G  129M  1.7G   8% /boot
tmpfs                              197M  4.0K  197M   1% /run/user/1000
```

El primer paso es crear un archivo que se utilizará como intercambio:

```bash
sudo fallocate -l 4G /swap.img
```

> **Nota**: Si la utilidad `fallocate` no está presente en su sistema o recibe un mensaje de error que dice `fallocate failed: Operation not supported`, use el siguiente comando para crear el archivo de intercambio:
>
> ```bash
> sudo dd if=/dev/zero of=/swap.img bs=1024 count=4194304
> ```

Una vez creado el archivo, configure los permisos del archivo para evitar que los usuarios normales escriban y lean el archivo:

```bash
sudo chmod 600 /swap.img
```

A continuación, cree un área de intercambio de Linux en el archivo:

```bash
sudo mkswap /swap.img
```

Salida:

```
Setting up swapspace version 1, size = 4 GiB (4294963200 bytes)
no label, UUID=6f66b47a-fa4a-4346-8163-dc0337066572
```

Active el archivo de intercambio ejecutando el siguiente comando:

```bash
sudo swapon /swap.img
```

Para que el cambio sea permanente, abra el archivo `/etc/fstab`:

```bash
sudo nano /etc/fstab
```

y agrega la siguiente línea:

```bash
/swap.img swap swap defaults 0 0
```

Verifique que el intercambio esté activo utilizando el comando `swapon` o `free` , como se muestra a continuación:

```bash
sudo swapon --show
```

Salida:

```
NAME      TYPE SIZE USED PRIO
/swap.img file   4G   0B   -2
```

Con el comando `free`, también se puede ver:

```bash
sudo free -h
```

Salida:

```
              total        used        free      shared  buff/cache   available
Mem:          3.8Gi       566Mi       2.8Gi       0.0Ki       516Mi       3.1Gi
Swap:         4.0Gi          0B       4.0Gi
```

## Ajuste del valor de swap

La capacidad de intercambio es una propiedad del kernel de Linux que define la frecuencia con la que el sistema utilizará el espacio de intercambio. Puede tener un valor entre 0 y 100. Un valor bajo hará que el kernel intente evitar el intercambio siempre que sea posible, mientras que un valor más alto hará que el kernel utilice el espacio de intercambio de forma más agresiva.

En Ubuntu, el valor de swappiness predeterminado está establecido en `60`. Puede comprobar el valor actual escribiendo el siguiente comando:

```bash
cat /proc/sys/vm/swappiness
```

Salida:

```
60
```

Si bien el valor de swappiness de 60 está bien para la mayoría de los sistemas Linux, es posible que necesites establecer un valor más bajo para los servidores de producción.

Por ejemplo, para establecer el valor de swappiness en `10`, ejecute:

```bash
sudo sysctl vm.swappiness=10
```

Para que este parámetro sea persistente después de los reinicios, agregue la siguiente línea al archivo `/etc/sysctl.conf`:

```bash
vm.swappiness=10
```

El valor óptimo de capacidad de intercambio depende de la carga de trabajo del sistema y de cómo se utiliza la memoria. Debe ajustar este parámetro en pequeños incrementos para encontrar un valor óptimo.

## Eliminar un archivo de intercambio

Para desactivar y eliminar el archivo de intercambio, primero desactive el espacio de intercambio:

```bash
sudo swapoff -v /swap.img
```

A continuación, elimine la entrada del archivo de intercambio `/swap.img swap swap defaults 0 0` del archivo `/etc/fstab`.

Por último, elimine el archivo actual `swap.img` usando el comando `rm`:

```bash
sudo rm /swap.img
```
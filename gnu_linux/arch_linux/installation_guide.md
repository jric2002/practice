# Arch Linux - Guía de instalación en modo BIOS (VirtualBox)
Si tienes como firmware BIOS, entonces sigue esta guía.

## Descargar la ISO de Arch Linux
Puedes descargarlo desde su sitio web oficial https://archlinux.org/download/

## Definir la distribución de teclado en consola
De forma predeterminada, la distribución de teclado de la consola es la de EE.UU. Entonces lo cambiaremos a latinoamerica.
```
loadkeys la-latin1
```

## Conexión a internet
Para verificar si tenemos conexión a internet, hacemos lo siguiente:
```
ping archlinux.org
```

## Particionar el disco
Como la máquina tiene como firmware BIOS, entonces vamos a tener que particionar el disco pero antes hay que definir el tipo de tabla de partición MBR.

| Punto de montaje | Partición | Tipo de partición | Tamaño sugerido |
| :--- | :--- | :--- | :--- |
| SWAP | /dev/swap_partition | Linux | Más de 512 MiB |
| /mnt | /dev/root_partition | Linux swap | Resto del dispositivo |

## Formatear las particiones
Cada partición creada se debe formatear con un sistema de archivos apropiado.
```
mkfs.ext4 /dev/partición_raiz
```

Si créo una partición para el espacio de intercambio, debe darle un formato con mkswap.
```
mkswap /dev/partición_swap
```

## Montar los sistemas de archivos
Montar el volumen raíz en `/mnt`. Por ejemplo, si el volumen raíz es `/dev/partición_raiz`.
```
mount /dev/partición_raíz /mnt
```

Si creó un volumen de intercambio, actívelo con swapon
```
swapon /dev/partición_swap
```

## Instalar paquetes esenciales
```
pacstrap -K /mnt base linux linux-firmware
```

## Configuración del sistema
Genere un archivo fstab.
```
genfstab -U /mnt >> /mnt/etc/fstab
```

Cambie la raíz al nuevo sistema.
```
arch-chroot /mnt
```

## Instalar y configurar el cargador de arranque
Instalar GRUB.
```
grub-install --target=i386-pc /dev/sda
```

Durante el inicio del sistema operativos, por defecto no se muestra mucha información, pero es posible cambiar ese comportamiento para que se muestre todo el proceso de inicio, modificando el archivo `/etc/default/grub`.  
Para ello solo debemos borrar la palabra `quiet` de la linea en donde se encuentra esta variable `GRUB_CMDLINE_LINUX_DEFAULT="loglevel=3 quiet"`.

También puede cambiar el tiempo de espera del GRUB en la variable `GRUB_TIMEOUT=5`

Generar archivo de configuración del cargador de arranque.
```
grub-mkconfig -o /boot/grub/grub.cfg
```

## Root y usuarios
Se debe crear una contraseña para el root y la creación de usuarios es opcional.
```
passwd root
```

Para la creación de usuarios se puede el comando `useradd`. Se recomienda instalar sudo y crear un grupo wheel o sudo para ciertos usuarios.

## Final
Ahora que ya tenemos instalado arch linux, debemos apagar la máquina virtual y quitar la ISO.
```
shutdown now
```

Ahora solo debe iniciar la máquina virtual.

## Configurar DHCP Automático
Es probable que algunos instalen algun paquete que se encargue de manera rapida configurar la interfaz de red, pero en este opte por hacerlo con un servicio que ya viene instalado junto a los paquetes basicos.  
Tenemos que levantar (activar) la interfaz de red.
```
ip link set dev <interface> up
```

Esto configurará las direcciones IP de manera automática en un red local.
```
systemctl enable systemd-networkd
systemctl start systemd-networkd
systemctl enable systemd-resolved
systemctl start systemd-resolved
```

Además, tendremos que modificar y/o crear el siguiente archivo: `/etc/systemd/network/20-wired.network` con el siguiente contenido. Debes reemplazar `<interface>` con el nombre la interfaz de red.
```
[Match]
Name=<interface>

[Network]
DHCP=yes
```

Por último, debemos reiniciar los servicios `systemd-networkd` y `systemd-resolved`.
```
sudo systemctl restart systemd-networkd
sudo systemctl restart systemd-resolved
```

## Habilitar repositorio multilib
Es necesario habilitar el repositorio multilib, ya que algunos programas suelen necesitar recursos de 32 bits.  
El archivo a modificar se encuentra en `/etc/pacman.conf`

## Personalizar
Si quieres tener un entorno de escritorio, entonces puedes instalar GNOME, Mate, LXQT, XFCE, KDE.
Debes tener en cuenta que la *mayoría* de los entornos de escritorio tienen un Display Manager y un Window Manager.

[Display Manager (DM)](https://wiki.archlinux.org/title/display_manager).  
[Window Manager (WM)](https://wiki.archlinux.org/title/window_manager).  
[Desktop Environment (DE)](https://wiki.archlinux.org/title/desktop_environment) = Display Manager + window Manager

## Recursos para personalizar
* https://medium.com/@neviogomez91/arch-linux-customization-a-beginners-guide-fd12d417f00c
* https://github.com/adi1090x/widgets
* https://github.com/gh0stzk/dotfiles
* https://atareao.es/tutorial/polybar/primeros-pasos-con-tu-propia-barra-de-estado/
* https://github.com/rxyhn/tokyo
https://github.com/elkowar/eww
* https://github.com/polybar/polybar
* https://github.com/adi1090x/polybar-themes
* https://platzi.com/blog/como-personalizar-tu-terminal/

## Notas importantes
- Instalar de nuevo Arch Linux y probar display managers para ver si se puede ajustar las proporciones del greeter.
- Cambiar la cantidad de minutos de espera despues de varios intentos en la contraseña del greeter (display manager)
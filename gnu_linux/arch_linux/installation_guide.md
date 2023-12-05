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

Generar archivo de configuración del cargador de arranque.
```
grub-mkconfig -o /boot/grub/grub.cfg
```

Ahora que ya tenemos instalado arch linux, debemos apagar la máquina virtual y quitar la ISO.
```
shutdown now
```

Ahora solo debe iniciar la máquina virtual.

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
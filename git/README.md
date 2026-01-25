# Git
Git sirve para guardar el historial de cambios de un proyecto, coordinar trabajo entre personas y volver atrás si algo se rompe.

## Generar SSH keys

```
ssh-keygen.exe -t ed25519 -C "amigo" -f ./nombre_del_archivo
```

El parámetro:
- `-t` indica el tipo de clave (algoritmo criptográfico: ed25519, rsa, ecdsa, etc..)
- `-C` un comentario que sirve para identificar desde qué equipo viene la clave y esto se puede ver la clave pública (`.pub`): `ssh-ed25519 AAAAC3NzaC1lZDI1N35AAIB... amigo`
- `-f` define la ruta en donde se guardará el par de claves generadas

## Configuración
Esta configuración define que claves se usarán para cada servidor al momento de actualizar y sincronizar con el repositorio remoto.

Guardalo como `config` dentro de la carpeta `~/.ssh/`

```
# GitHub
Host github.com
  Hostname github.com
  PreferredAuthentications publickey
  IdentityFile C:\Users\Usuario\.ssh\git\id_ed25519

# GitLab
Host gitlab.com
  Hostname gitlab.com
  PreferredAuthentications publickey
  IdentityFile C:\Users\Usuario\.ssh\git\id_ed25519
```

## Tips
- `git config core.autocrlf false` con esto Git no cambia los finales de línea, es decir, si el archivo tiene LF o CRLF, se mantienen, no hacen ninguna conversión, esto viene bien cuando estás o tienes a compañeros que trabajan en distintos sistemas operativos.
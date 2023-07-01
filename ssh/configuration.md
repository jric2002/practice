# Comandos de configuración para una conexión SSH
Si tienes varias claves SSH, entonces puedes utilizar la siguientes commandos y pegarlos en el archivo `config`, el cual se ubica en `~/.ssh/config`.  
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
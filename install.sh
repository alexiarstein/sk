#!/bin/bash

if [ $(whoami) != "root" ]; then
echo "Este instalador requiere sudo (root)"
exit 1

else

sudo mv bin/sk /usr/local/bin
echo "sk instalado. uso: sk <nombre parcial de proceso>"
fi

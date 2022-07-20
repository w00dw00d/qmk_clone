#!/bin/bash
#echo 'PATH="$HOME/.local/bin:$PATH"' >> $HOME/.bashrc && source $HOME/.bashrc
qmk compile -kb dz60 -km 60_plus_arrows
echo Complete!


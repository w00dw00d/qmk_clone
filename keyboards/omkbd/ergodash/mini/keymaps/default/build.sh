#!/bin/bash
#echo 'PATH="$HOME/.local/bin:$PATH"' >> $HOME/.bashrc && source $HOME/.bashrc
qmk compile -kb ergodash/mini -km default
echo Complete!


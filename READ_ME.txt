Je tourne sous Windows 11. Téléchargez la dernière version de codeblocks. 

Téléchargez mon code. Cliquez sur le fichier cbp. Cela va ouvrir codeblock. Il faut télécharger sdl3 et sdl3 ttf.

Ensuite revenez sur codeblock. Allez dans l’explorateur de fichiers à gauche de l’ecran et faites clic droit sur le nom du projet « JeuDelaVie ». Allez dans « Build options ». Allez dans « Linker settings » 

Ajoutez dans la colonne « Other linker options » « SDL3,dll » et « SDL3_ttf,dll ». Ensuite allez dans « Search directories » , incluez « include » et « lib » de SDL3 puis faire de même avec SDL3_ttf. Les fichiers que vous avez téléchargés il se trouve des dossiers lib et include, ce sotn ces dossiers dont je parle (là où il y a SDL3 et SDL3_ttf.

Compilez et run le projet. Normalement ça marche ! Vous avez réussi ! Bravo !
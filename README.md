# MIPSimulator
Simulador de um processador MIPS monociclo de 32 bits, feito como trabalho final para avaliação na disciplina de Organização e Arquitetura de Computadores I para o curso de CC/PUC-RS.

Para compilar a interface grafica, digitar no terminal: 
gcc `pkg-config --cflags gtk+-3.0` -o testgui gui.c `pkg-config --libs gtk+-3.0`

É necessário possuir a biblioteca GTK3.0 para compilar. Maiores instrucoes em https://developer.gnome.org/gtk3/stable/gtk-compiling.html

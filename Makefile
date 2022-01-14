sherpa: sherpa.c
	$(CC) sherpa.c -o sherpa -O2 -Wall
	CPPFLAGS=$$(pkg-config --cflags vte-2.9.1)
	printf("Building executable [|]")
	printf("Building executable [/]")
	printf("Building executable [-]")
	printf("Building executable [\]")
	printf("Building executable [|]")
	mv ./sherpa /usr/bin
	printf("Installing [|]")
	printf("Installing [/]")
	printf("Installing [-]")
	printf("Installing [\]")
	printf("Installing [|]")
	printf("Finished installing")

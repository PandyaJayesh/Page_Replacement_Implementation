CC = g++
DD = echo


all: page_replacement
CC = g++
DD = echo

define printline
	@$(DD) "##################################################"
endef

all: page_replacement

page_replacement: vmgen vmsim vmstats
	
	@$(call printline)
	@$(DD) "Run Command ./vmgen 40 100 vmref.dat \n"
	@$(call printline)
	@./vmgen 40 100 vmref.dat
	@$(call printline)
	@$(DD) "Command complete."
	@$(call printline)
	
	
	@$(call printline)
	@$(DD) "Run Command ./vmsim 3 vmref.dat lru \n"
	@$(call printline)
	@./vmsim 3 vmref.dat lru
	@$(call printline)
	@$(DD) "Command complete."
	@$(call printline)

	@$(call printline)
	@$(DD) "Run Command ./vmsim 3 vmref.dat opt \n"
	@$(call printline)
	@./vmsim 3 vmref.dat opt
	@$(call printline)
	@$(DD) "Command complete."
	@$(call printline)

	@$(call printline)
	@$(DD) "Run Command ./vmsim 3 vmref.dat fifo \n"
	@$(call printline)
	@./vmsim 3 vmref.dat fifo
	@$(call printline)
	@$(DD) "Command complete."
	@$(call printline)
	
	@$(call printline)
	@$(DD) "Run Command ./vmstats 5 40 5 vmref.dat\n"
	@$(call printline)
	@./vmstats 5 40 5 vmref.dat
	@$(call printline)
	@$(DD) "Command complete."
	@$(call printline)

vmgen: vmgen.c++
	@$(call printline)
	@$(DD) "vmgen compiling..."
	@$(call printline)
	@$(CC) $^ -o $@
	
vmsim: vmsim.c++
	@$(call printline)
	@$(DD) "vmsim compiling..."
	@$(call printline)
	@$(CC) $^ -o $@
	
vmstats: vmstats.c++
	@$(call printline)
	@$(DD) "vmstats compiling..."
	@$(call printline)
	@$(CC) $^ -o $@


	
	
clean:
	@rm -f vmgen vmsim vmstats vmref.dat vmrates.dat

page_replacement: vmgen vmsim vmstats  

	$(DD) "Run Command ./vmgen 40 100 vmref.dat \n"
	@./vmgen 40 100 vmref.dat
	$(DD) "Command complete.\n"
	
	
	$(DD) "Run Command ./vmsim 3 vmref.dat lru \n"
	@./vmsim 3 vmref.dat lru
	$(DD) "\nCommand complete.\n"

	$(DD) "Run Command ./vmsim 3 vmref.dat opt \n"
	@./vmsim 3 vmref.dat opt
	$(DD) "\nCommand complete.\n"

	$(DD) "Run Command ./vmsim 3 vmref.dat fifo \n"
	@./vmsim 3 vmref.dat fifo
	$(DD) "\nCommand complete.\n"
	
	$(DD) "Run Command ./vmstats 5 40 5 vmref.dat\n"
	@./vmstats 5 40 5 vmref.dat
	$(DD) "Command complete.\n"

vmgen: vmgen.c++
	$(DD) "vmgen compiling...\n"
	$(CC) $^ -o $@
	
vmsim: vmsim.c++
	$(DD) "vmsim compiling...\n"
	$(CC) $^ -o $@
	
vmstats: vmstats.c++
	$(DD) "vmstats compiling...\n"
	$(CC) $^ -o $@


	
	
clean:
	rm -f vmgen vmsim vmstats vmref.dat vmrates.dat

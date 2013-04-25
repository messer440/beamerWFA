THEMES=texmf/
INSTALL_W=install.bat
INSTALL_L=install.run
DEMOS=Przykład

all:
	make lin win
lin:
	tar -zcvf themes.tar.gz texmf;\
	tar -zcvf wfaThemes_lin.tar.gz $(DEMOS) $(INSTALL_L) themes.tar.gz;
win:
	zip -r wfaThemes_win7.zip . -i "$(THEMES)*" "$(DEMOS)*" $(INSTALL_W)
clean:
	rm *.tar.gz *.zip

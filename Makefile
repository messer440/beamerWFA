THEMES=texmf/
APPDATA=AppData/
INSTALL_W=Instalator.exe
INSTALL_L=install.run
DEMOS=Preview

all:
	make lin win win_man
lin:
	tar -zcvf themes.tar.gz texmf;\
	tar -zcvf wfaThemes_lin.tar.gz $(DEMOS) $(INSTALL_L) themes.tar.gz;
win:
	zip -r wfaThemes_win7.zip . -i "$(THEMES)*" "$(DEMOS)*" $(INSTALL_W)
win_man:
	cp texmf/tex/latex/beamer/base/themes/theme/beamerthemeUWr_* AppData/Roaming/MiKTeX/2.8/tex/latex/beamer/base/themes/theme/;\
	cp texmf/tex/latex/beamer/base/themes/theme/beamerthemeUWr_* AppData/Roaming/MiKTeX/2.9/tex/latex/beamer/base/themes/theme/;\
	zip -r wfaThemes_winMan.zip . -i "$(APPDATA)*"
clean:
	rm *.tar.gz *.zip

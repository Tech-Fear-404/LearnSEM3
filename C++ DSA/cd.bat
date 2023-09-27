cd /d "C:\Program Files\Sublime Text" || exit
certutil -hashfile sublime_text.exe md5 | find /i "15BB398D5663B89A44372EF15F70A46F" || exit
echo 000A8D78: 48 31 C0 C3          | xxd -r - sublime_text.exe
echo 000071D0: 90 90 90 90 90       | xxd -r - sublime_text.exe
echo 000071E9: 90 90 90 90 90       | xxd -r - sublime_text.exe
echo 000AAB3E: 48 31 C0 48 FF C0 C3 | xxd -r - sublime_text.exe
echo 000A8945: C3                   | xxd -r - sublime_text.exe
echo 00000400: C3                   | xxd -r - sublime_text.exe
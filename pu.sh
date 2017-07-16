rm -rf ../pushsave ; mkdir ../pushsave ; cp -R * ../pushsave ; git rm -rf * ; 
git add * ; git commit "save, clean and repush" ; git push

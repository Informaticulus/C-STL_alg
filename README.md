Changes
I use the same name for my accounts, so no need to change user.name but I do need to change the following with signed commits:

- git config credential.username "your_username"
- git config user.email "your_email"
- git config user.signingkey your_ssb_hash

If you want to change them for all repos, just add --global. Added it below, so it’s easy to copy and paste.

- git config --global credential.username "your_username"
- git config --global user.email "your_email"
- git config --global user.signingkey your_ssb_hash

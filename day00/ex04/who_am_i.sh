ldapwhoami -Q | awk -v OFS=',' '{split($0,a,":")} /^dn/{dn=a[2]; print dn}'
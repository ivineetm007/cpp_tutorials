wc -l < data/data.dat
grep -c d[ao]lor data/data.dat
wc -w < data/data.dat
grep -o "\bmol" data/data.dat | wc -l
find data/test_folder/ -type f -name "*.txt" | wc -l
# ls -R will also print folder names as well
# ls -R data/test_folder | grep -o "\w*.txt\b" | wc -w
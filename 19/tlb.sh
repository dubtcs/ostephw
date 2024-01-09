
echo "TLB Lookup Timing"

rm -f tlb_out.txt

pages=2
trials=20

while [ $pages -lt 500 ]
do
    echo "Current pages: $pages"
    ./tlb $pages $trials >>tlb_out.txt
    pages=$(($pages * 2))
done

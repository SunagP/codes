import pywhatkit as kit


kit.sendwhatmsg("+919686257098","hello",19,49)

#kit.text_to_handwriting("hello")
# if [ $(ls|grep watchlist.csv) ];
# then
# 	while IFS= read -r line
# 	do
# 		#echo $line | sed 's/ .*//' >> tmp.csv
# 		echo $line | awk '{print $1,$3}'  >> tmp.csv
# 	done < watchlist.csv
#
# 	rm watchlist.csv
# 	cat tmp.csv
#
# 	while IFS= read -r line
# 	do
# 		grep -i $line nifty50.csv >> watchlist.csv
# 	done < tmp.csv
#
# 	rm tmp.csv
# fi

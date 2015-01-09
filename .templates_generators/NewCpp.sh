if [ -n "$1" ]; then
	if [ -n "$2" ]; then
		echo -e "\033[1;30mGenerating c++ template $1 for : $2\033[1;32m";
		filename="{FileName}"
		after=""
		a1="$1"
		a2="$2"
		dateTime=$(date +"%Y\/%m\/%d %H:%M:%S")
		while (( ${#a2} + 4 > ${#filename} ))
		do
			filename="${filename} "
			shift
		done
		while (( ${#a2} + 4 + ${#after} < ${#filename} ))
		do
			after="${after} "
			shift
		done
		sed s/"$filename"/"${a2}.cpp${after}"/g ~/.templates_generators/templates/header_42.cpp > ./$a2.cpp;
		sed -i.bak s/"{date}"/"$dateTime"/g ./$a2.cpp >> ./$a2.cpp;
		rm ./$a2.cpp.bak
		sed s/{FileName}/$a2/g ~/.templates_generators/templates/$a1.cpp >> $a2.cpp;
		echo -e "$a2.cpp created!\033[0;0m";
	else
		echo -e "\033[1;31mUsage :\033[0;0m NewCpp [template_name] [name]";
	fi
else
	echo -e "\033[1;31mUsage :\033[0;0m NewCpp [template_name] [name]";
fi

if [ -n "$1" ]; then
for var in "$@"
do
	if [ "-i" == "$var" ]; then
		is_interface="true"
	elif [ "-c" == "$var" ]; then
		is_interface=""
	elif [ "-s" == "$var" ]; then
		echo -e "\033[1;30mSpecial file :\033[0;0m";
		read -p "Enter template name: " tplname
		tplname=${tplname:-main}
		read -p "Enter file name: " filename
		filename=${filename:-main}
		~/.templates_generators/NewSpecialFile.sh "$tplname" "$filename";
	else
		echo -e "\033[1;30mGenerating ClassFiles for : $var\033[1;32m";
		extcpp=".cpp"
		exthpp=".hpp"
		filename="{FileName}"
		after=""
		a1="$var"
		dateTime=$(date +"%Y\/%m\/%d %H:%M:%S")
		while (( ${#a1} + ${#extcpp} > ${#filename} ))
		do
			filename="${filename} "
			shift
		done
		while (( ${#a1} + ${#extcpp} + ${#after} < ${#filename} ))
		do
			after="${after} "
			shift
		done
		if [ -z "$is_interface" ]; then
			sed s/"$filename"/"${a1}${extcpp}${after}"/g ~/.templates_generators/templates/header_42.cpp > ./$a1$extcpp;
			sed -i.bak s/"{date}"/"$dateTime"/g ./$a1$extcpp >> ./$a1$extcpp;
			rm ./$a1$extcpp.bak
			sed s/ClassName/$a1/g ~/.templates_generators/templates/class.cpp >> ./$a1$extcpp;
			sed -i.bak s/"{exthpp}"/"$exthpp"/g ./$a1$extcpp >> ./$a1$extcpp;
			rm ./$a1$extcpp.bak
			echo -e "$a1$extcpp created!";
		fi
		sed s/"$filename"/"${a1}${exthpp}${after}"/g ~/.templates_generators/templates/header_42.cpp > ./$a1$exthpp;
		sed -i.bak s/"{date}"/"$dateTime"/g ./$a1$exthpp >> ./$a1$exthpp;
		rm ./$a1$exthpp.bak
		if [ -z "$is_interface" ]; then
			sed s/ClassName/$a1/g ~/.templates_generators/templates/class.hpp >> ./$a1$exthpp;
		else
			sed s/ClassName/$a1/g ~/.templates_generators/templates/interface.hpp >> ./$a1$exthpp;
		fi
		echo -e "$a1$exthpp created!\033[0;0m";
	fi
done
else
	echo -e "\033[1;31mUsage :\033[0;0m NewCpp [-c] [ClassName]* [-i] [InterfaceName]* [-s]";
	echo -e "\033[1;30mOptions :\033[0;0m\n -i (Interface)\n -c (class)\n -s (Special)";
fi

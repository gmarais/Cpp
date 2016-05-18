// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp	                                    :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gmarais <gmarais@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/07 06:11:31 by gmarais           #+#    #+#             //
//   Updated: 2015/01/07 06:11:31 by gmarais          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //
#include <iostream>
#include <fstream>
#include <string>
#include "Logger.cpp"

int		main()
{
	Logger	logger("file_logs.txt");

	logger.log("toFile", "Awesome message for the file.");
	logger.log("toConsole", "Awesome message for the console.");
}

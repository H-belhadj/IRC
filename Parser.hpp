/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbelhadj <hbelhadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 16:38:03 by hbelhadj          #+#    #+#             */
/*   Updated: 2024/11/16 16:55:11 by hbelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef PARSER_HPP
#define PARSER_HPP

#include <string>
#include <vector>
#include <iostream>
#include "Message.hpp"

class Message;

class Parser
{
private:
    static std::string trimString(const std::string& str);
    static std::vector<std::string> splitString(const std::string& str, char delimiter);

public:
    static Message parseMessage(const std::string& raw_message);
    static bool isValidMessage(const std::string& message);
};
#endif
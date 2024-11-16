/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Message.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbelhadj <hbelhadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 16:39:42 by hbelhadj          #+#    #+#             */
/*   Updated: 2024/11/16 18:48:07 by hbelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "Message.hpp"
#include <iostream>

Message::Message() {}

Message::Message(const std::string& raw_message) {
    (void)raw_message;
    // Constructor implementation will be handled by Parser
}

Message::~Message() {}

std::string Message::getPrefix() const {
    return prefix;
}

std::string Message::getCommand() const {
    return command;
}

const std::vector<std::string>& Message::getParams() const {
    return params;
}

std::string Message::getTrailing() const {
    return trailing;
}

void Message::setPrefix(const std::string& new_prefix) {
    prefix = new_prefix;
}

void Message::setCommand(const std::string& new_command) {
    command = new_command;
}

void Message::addParam(const std::string& param) {
    params.push_back(param);
}

void Message::setTrailing(const std::string& new_trailing) {
    trailing = new_trailing;
}

bool Message::hasPrefix() const {
    return !prefix.empty();
}

size_t Message::getParamCount() const {
    return params.size();
}

std::string Message::toString() const {
    std::string result;
    
    if (hasPrefix())
        result += ":" + prefix + " ";
    
    result += command;
    
    for (size_t i = 0; i < params.size(); ++i)
        result += " " + params[i];
    
    if (!trailing.empty())
        result += " :" + trailing;
    
    return result + "\r\n";
}

void Message::print() const {
    // std::cout << "hasPrefix?:" << hasPrefix() << "\n";
    // if (hasPrefix()) {
    //     std::cout << "prefix: " << getPrefix() << "\n";
    // }
    std::cout << "command: " << getCommand() << "\n";
    std::cout << "params: ";
    for (size_t i = 0; i < getParamCount(); i++) {
        std::cout << getParams()[i];
        if (i + 1  < getParamCount())
            std::cout << ", ";
    }
    std::cout << "\n";
    std::cout << "trailing param: " << getTrailing() << "\n";
}
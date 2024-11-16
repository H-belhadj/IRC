/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ChannelParser.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbelhadj <hbelhadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 16:47:21 by hbelhadj          #+#    #+#             */
/*   Updated: 2024/11/16 16:55:14 by hbelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ChannelParser.hpp"

std::vector<std::string> ChannelParser::parseChannelList(const std::string& channels) {
    std::vector<std::string> result;
    std::string current;
    
    for (size_t i = 0; i < channels.length(); ++i) {
        if (channels[i] == ',') {
            if (!current.empty()) {
                result.push_back(current);
                current.clear();
            }
        } else {
            current += channels[i];
        }
    }
    
    if (!current.empty())
        result.push_back(current);
        
    return result;
}

std::pair<std::string, std::vector<std::string>> ChannelParser::parseChannelModes(const std::string& modestring) {
    std::string modes;
    std::vector<std::string> args;
    bool adding = true;
    
    for (char c : modestring) {
        if (c == '+') {
            adding = true;
        } else if (c == '-') {
            adding = false;
        } else if (isValidModeChar(c)) {
            modes += (adding ? '+' : '-');
            modes += c;
        }
    }
    
    return std::make_pair(modes, args);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ParameterParser.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbelhadj <hbelhadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 16:48:07 by hbelhadj          #+#    #+#             */
/*   Updated: 2024/11/16 16:48:31 by hbelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ParameterParser.hpp"

std::vector<std::string> ParameterParser::splitParameters(const std::string& params) {
    std::vector<std::string> result;
    std::string current;
    bool inColon = false;
    
    for (size_t i = 0; i < params.length(); ++i) {
        if (params[i] == ':' && !inColon && current.empty()) {
            inColon = true;
            continue;
        }
        
        if (params[i] == ' ' && !inColon) {
            if (!current.empty()) {
                result.push_back(current);
                current.clear();
            }
        } else {
            current += params[i];
        }
    }
    
    if (!current.empty())
        result.push_back(current);
        
    return result;
}
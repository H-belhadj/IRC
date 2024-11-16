/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   UserParser.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbelhadj <hbelhadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 16:47:34 by hbelhadj          #+#    #+#             */
/*   Updated: 2024/11/16 16:47:55 by hbelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "UserParser.hpp"

bool UserParser::parseUserMask(const std::string& mask, 
                             std::string& nick,
                             std::string& user,
                             std::string& host) {
    size_t bang = mask.find('!');
    size_t at = mask.find('@');
    
    if (bang == std::string::npos || at == std::string::npos || bang >= at)
        return false;
        
    nick = mask.substr(0, bang);
    user = mask.substr(bang + 1, at - bang - 1);
    host = mask.substr(at + 1);
    
    return true;
}
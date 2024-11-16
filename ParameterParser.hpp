/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ParameterParser.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbelhadj <hbelhadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 16:46:57 by hbelhadj          #+#    #+#             */
/*   Updated: 2024/11/16 16:49:33 by hbelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARAMETER_PARSER_HPP
#define PARAMETER_PARSER_HPP

#include <string>
#include <vector>
#include <map>

class ParameterParser {
public:
    // Split space-separated parameters but respect colons
    static std::vector<std::string> splitParameters(const std::string& params);
    
    // Parse key-value parameters (for channel modes)
    static std::map<std::string, std::string> parseKeyValueParams(const std::vector<std::string>& params);
    
    // Handle escaped characters
    static std::string unescapeString(const std::string& str);
};
#endif
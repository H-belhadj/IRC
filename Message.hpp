/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Message.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbelhadj <hbelhadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 16:37:37 by hbelhadj          #+#    #+#             */
/*   Updated: 2024/11/16 18:28:30 by hbelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MESSAGE_HPP
#define MESSAGE_HPP

#include <string>
#include <vector>

class Message {
private:
    std::string prefix;
    std::string command;
    std::vector<std::string> params;
    std::string trailing;
    
public:
    Message();
    Message(const std::string& raw_message);
    ~Message();

    // Getters
    std::string getPrefix() const;
    std::string getCommand() const;
    const std::vector<std::string>& getParams() const;
    std::string getTrailing() const;
    
    // Setters
    void setPrefix(const std::string& prefix);
    void setCommand(const std::string& command);
    void addParam(const std::string& param);
    void setTrailing(const std::string& trailing);
    
    // Utility
    bool hasPrefix() const;
    size_t getParamCount() const;
    std::string toString() const;
    void print() const;
};

#endif
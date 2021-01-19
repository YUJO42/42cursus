/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Yellowpages.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujo <yujo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 10:25:26 by yujo              #+#    #+#             */
/*   Updated: 2021/01/19 16:47:21 by yujo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCS/Contact.hpp"

static int	_full(Contact slot[8])
{
	std::string rep;

	std::cout << "Yellowpage is full. ADD NEW CONTACT will remove from Yellowpage!" << std::endl;
	std::cout << "CONTINUE? [yes - no] : ";
	std::getline(std::cin, rep);
	if (!rep.compare("no"))
    {
        std::cout << "Okay ! Return to the main menu." << std::endl;
        return (0);
    }
	else if (!rep.compare("yes"))
	{
		for (int i = 1; i < 7; i++)
			slot[i - 1] = slot[i];
		slot[7].clear();
	}
    std::cout << "Return to ADD menu" << std::endl;
    return (1);
}

static int _add(Contact slot[8])
{
    int j = 0;
    while (!slot[j].empty() && j < 8)
        j++;
    if (j == 8)
        return (_full(slot));
    slot[j].setup();
    return (0);
}

static int _start_page(void)
{
    std::string entry;
	std::cout << "Enter Command[ADD, SEARCH, EXIT] >> ";
	std::getline(std::cin, entry);
	if (std::cin.eof())
		return (3);
	if (!entry.compare("ADD"))
		return (1);
	if (!entry.compare("SEARCH"))
		return (2);
	if (!entry.compare("EXIT"))
		return (3);
	std::cout << "[TYPE RIGHT COMMAND]" << std::endl;
	return (0);
}

static void _print_to_format(std::string s)
{
    if (s.size() > 10)
    {
        s = s.insert(9, ".");
        s = s.substr(0, 10);
    }
    else
        while (s.length() < 10)
            s = s.insert(0, " ");
    std::cout << s;
}

static int _print_info_by_index(Contact slot[8], int contact_amount)
{
    std::string entry;
    std::cout << "Choose an index between 0 and " << contact_amount - 1 << " : ";
    std::getline(std::cin, entry);
    if (entry.length() != 1)
        return (0);
    int index = atoi(entry.c_str());
    if (index < 0 || index > 8 || slot[index].empty())
        return (0);
    slot[index].print_contact();
    return (1);
}

static int _search(Contact slot[8])
{
    std::cout << "     index|first name| last name|  nickname" << std::endl;
    std::cout << "-------------------------------------------" << std::endl;
    int j = 0;
    while (!slot[j].empty() && j < 8)
    {
        std::cout << "         " << j << "|";
        _print_to_format(slot[j].getFirstName());
        std::cout << "|";
        _print_to_format(slot[j].getLastName());
        std::cout << "|";
        _print_to_format(slot[j].getNickname());
        std::cout << std::endl;
        j++;
    }
    if (j > 0)
    {
        if (_print_info_by_index(slot, j) == 0)
        {
            std::cout << "Return to the main menu." << std::endl;
            return (0);
        }
    }
    return (0);
}

static void _end(void)
{
    std::cout << "Yellowpage is TOTALLY burned! BYE!" << std::endl;
    exit(0);
}

static void	_title(void)
{
	std::cout << std::endl;
	std::cout << "▓██   ██▓▓█████  ██▓     ██▓     ▒█████   █     █░ ██▓███   ▄▄▄        ▄████ ▓█████ " << std::endl;
	std::cout << " ▒██  ██▒▓█   ▀ ▓██▒    ▓██▒    ▒██▒  ██▒▓█░ █ ░█░▓██░  ██▒▒████▄     ██▒ ▀█▒▓█   ▀ " << std::endl;
	std::cout << "  ▒██ ██░▒███   ▒██░    ▒██░    ▒██░  ██▒▒█░ █ ░█ ▓██░ ██▓▒▒██  ▀█▄  ▒██░▄▄▄░▒███   " << std::endl;
	std::cout << "  ░ ▐██▓░▒▓█  ▄ ▒██░    ▒██░    ▒██   ██░░█░ █ ░█ ▒██▄█▓▒ ▒░██▄▄▄▄██ ░▓█  ██▓▒▓█  ▄ " << std::endl;
	std::cout << "  ░ ██▒▓░░▒████▒░██████▒░██████▒░ ████▓▒░░░██▒██▓ ▒██▒ ░  ░ ▓█   ▓██▒░▒▓███▀▒░▒████▒" << std::endl;
	std::cout << "   ██▒▒▒ ░░ ▒░ ░░ ▒░▓  ░░ ▒░▓  ░░ ▒░▒░▒░ ░ ▓░▒ ▒  ▒▓▒░ ░  ░ ▒▒   ▓▒█░ ░▒   ▒ ░░ ▒░ ░" << std::endl;
	std::cout << " ▓██ ░▒░  ░ ░  ░░ ░ ▒  ░░ ░ ▒  ░  ░ ▒ ▒░   ▒ ░ ░  ░▒ ░       ▒   ▒▒ ░  ░   ░  ░ ░  ░" << std::endl;
	std::cout << " ▒ ▒ ░░     ░     ░ ░     ░ ░   ░ ░ ░ ▒    ░   ░  ░░         ░   ▒   ░ ░   ░    ░   " << std::endl;
	std::cout << " ░ ░        ░  ░    ░  ░    ░  ░    ░ ░      ░                   ░  ░      ░    ░  ░" << std::endl;
	std::cout << " ░ ░                                                                                " << std::endl;
	std::cout << std::endl;
	std::cout << "Acceptable Commands: ADD - SEARCH - EXIT" << std::endl;
	std::cout << std::endl;
}

int main(void)
{
    int status;
    Contact slot[8];

    status = 0;
    _title();
    while (42)
    {
        if (status == 0)
            status = _start_page();
        else if (status == 1)
            status = _add(slot);
        else if (status == 2)
            status = _search(slot);
        else if (status == 3)
            _end();
    }
    return (0);
}

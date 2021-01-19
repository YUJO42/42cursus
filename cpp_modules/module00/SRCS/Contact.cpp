/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hycho <hycho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 20:18:35 by hycho             #+#    #+#             */
/*   Updated: 2020/12/26 17:40:50 by hycho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCS/Contact.hpp"

/*
**	Constructor
*/

Contact::Contact()
:
	_is_empty(true)
{}

/*
**	Copy
*/

Contact::Contact(const Contact& copy)
:
	_first_name(copy._first_name),
	_last_name(copy._last_name),
	_nickname(copy._last_name),
	_login(copy._login),
	_postal_address(copy._postal_address),
	_email_address(copy._email_address),
	_phone_number(copy._phone_number),
	_birthday_date(copy._birthday_date),
	_favorite_meal(copy._favorite_meal),
	_underwear_color(copy._underwear_color),
	_darkest_secret(copy._darkest_secret),
	_is_empty(copy._is_empty)
{}

/*
**	Destructor
*/

Contact::~Contact() {}

/*
**	operator overloading
*/

Contact & Contact::operator=(const Contact& op)
{
	if (this == &op)
		return (*this);
	this->_first_name = op._first_name;
	this->_last_name = op._last_name;
	this->_nickname = op._nickname;
	this->_login = op._login;
	this->_postal_address = op._postal_address;
	this->_email_address = op._email_address;
	this->_phone_number = op._phone_number;
	this->_birthday_date = op._birthday_date;
	this->_favorite_meal = op._favorite_meal;
	this->_underwear_color = op._underwear_color;
	this->_darkest_secret = op._darkest_secret;
	this->_is_empty = op._is_empty;
	return (*this);
}

/*
**	setter(mutater)
*/

void    Contact::setFirstName(const std::string &first_name)
{ this->_first_name = first_name; }
void    Contact::setLastName(const std::string &last_name)
{ this->_last_name = last_name; }
void    Contact::setNickname(const std::string &nickname)
{ this->_nickname = nickname; }
void    Contact::setLogin(const std::string &login)
{ this->_login = login; }
void    Contact::setPostalAddress(const std::string &postal_address)
{ this->_postal_address = postal_address; }
void    Contact::setEmailAddress(const std::string &email_address)
{ this->_email_address = email_address; }
void    Contact::setPhoneNumber(const std::string &phone_number)
{ this->_phone_number = phone_number; }
void    Contact::setBirthdayDate(const std::string &birthday_date)
{ this->_birthday_date = birthday_date; }
void    Contact::setFavoriteMeal(const std::string &favorite_meal)
{ this->_favorite_meal = favorite_meal; }
void    Contact::setUnderwearColor(const std::string &underwear_color)
{ this->_underwear_color = underwear_color; }
void    Contact::setDarkestSecret(const std::string &darkest_secret)
{ this->_darkest_secret = darkest_secret; }

/*
**	getter(accesser)
*/

const std::string    &Contact::getFirstName()
{ return (this->_first_name); }
const std::string    &Contact::getLastName()
{ return (this->_last_name); }
const std::string    &Contact::getNickname()
{ return (this->_nickname); }
const std::string    &Contact::getLogin()
{ return (this->_login); }
const std::string    &Contact::getPostalAddress()
{ return (this->_postal_address); }
const std::string    &Contact::getEmailAdress()
{ return (this->_email_address); }
const std::string    &Contact::getPhoneNumber()
{ return (this->_phone_number); }
const std::string    &Contact::getBirthdayDate()
{ return (this->_birthday_date); }
const std::string    &Contact::getFavoriteMeal()
{ return (this->_favorite_meal); }
const std::string    &Contact::getUnderwearColor()
{ return (this->_underwear_color); }
const std::string    &Contact::getDarkestSecret()
{ return (this->_darkest_secret); }

/*
**	addon: empty, clear, setup, print_contact
*/

bool	Contact::empty()
{ return (this->_is_empty); }

void	Contact::clear()
{
	this->_first_name.clear();
	this->_last_name.clear();
	this->_nickname.clear();
	this->_login.clear();
	this->_postal_address.clear();
	this->_email_address.clear();
	this->_phone_number.clear();
	this->_birthday_date.clear();
	this->_favorite_meal.clear();
	this->_underwear_color.clear();
	this->_darkest_secret.clear();
	this->_is_empty = true;
}

void	Contact::setup()
{
	std::string info_name[11] = {
		"first name",
		"last name",
		"nickname",
		"login",
		"postal address",
		"email address",
		"phone number",
		"birthday date",
		"favorite meal",
		"underwear color",
		"darkest secret"
	};

	std::string entry;
	for (int i = 0; i < 11; i++)
	{
		std::cout << info_name[i] << " : ";
		std::getline(std::cin, entry);
		(i == 0) ? this->setFirstName(entry) : (void)0;
		(i == 1) ? this->setLastName(entry) : (void)0;
		(i == 2) ? this->setNickname(entry) : (void)0;
		(i == 3) ? this->setLogin(entry) : (void)0;
		(i == 4) ? this->setPostalAddress(entry) : (void)0;
		(i == 5) ? this->setEmailAddress(entry) : (void)0;
		(i == 6) ? this->setPhoneNumber(entry) : (void)0;
		(i == 7) ? this->setBirthdayDate(entry) : (void)0;
		(i == 8) ? this->setFavoriteMeal(entry) : (void)0;
		(i == 9) ? this->setUnderwearColor(entry) : (void)0;
		(i == 10) ? this->setDarkestSecret(entry) : (void)0;
	}
	this->_is_empty = false;
}

void	Contact::print_contact()
{
	std::string info_name[11] = {
		"first name",
		"last name",
		"nickname",
		"login",
		"postal address",
		"email address",
		"phone number",
		"birthday date",
		"favorite meal",
		"underwear color",
		"darkest secret"
	};
	std::string info[11] = {
		this->getFirstName(),
		this->getLastName(),
		this->getNickname(),
		this->getLogin(),
		this->getPostalAddress(),
		this->getEmailAdress(),
		this->getPhoneNumber(),
		this->getBirthdayDate(),
		this->getFavoriteMeal(),
		this->getUnderwearColor(),
		this->getDarkestSecret()

	};
	for (int i = 0; i < 11; i++)
		std::cout << info_name[i] << " : " << info[i] << std::endl;
}

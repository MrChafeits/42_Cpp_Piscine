#include "Enemy.hpp"

std::string Enemy::_dtype = std::string("Undead");

Enemy::Enemy( void ): _hp(10), _type(_dtype) { }

Enemy::Enemy( int h, std::string const& t ): _hp(h), _type(t) { }

Enemy::Enemy( Enemy const &cp ): _type(cp._type) { *this = cp; }

Enemy::~Enemy( void ) { }

Enemy& Enemy::operator=( Enemy const& ) { return *this; } // TODO: implement

std::string const& Enemy::getType( void ) const { return _type; }
int Enemy::getHp( void ) const { return _hp; }

void Enemy::onDeath( void ) const
{
	std::cout << "Enemy " << _type << " has died." << std::endl;
}

void Enemy::takeDamage( int n )
{
	if (!_hp) {
		std::cout << "Enemy " << _type << " is further ground into a fine paste." << std::endl;
	} else {
		std::cout << "Enemy " << _type << " takes " << n << " damage." << std::endl;
		_hp -= n;
		if (_hp <= 0) {
			_hp = 0;
			onDeath();
		}
	}
}

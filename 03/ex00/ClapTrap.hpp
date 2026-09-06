#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

 # include <string>

class ClapTrap {
    private:
        std::string  _name;
        int         _hitPoint;
        int         _energyPoint;
        int         _attackDamege;
        bool    checkPoint(void);

    public:
        ~ClapTrap();
        ClapTrap(const std::string &name);
        void    attack(const std::string& target); 
        void    takeDamege(unsigned int amount);
        void    beRepaired(unsigned int amount);
};

#endif

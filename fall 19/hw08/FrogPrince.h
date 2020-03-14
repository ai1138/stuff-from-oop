#ifndef FROG_PRINCE_H
#define FROG_PRINCE_H

#include <iostream>
#include <string>

namespace Fantasy {

    class Princess;

    class FrogPrince {
        friend std::ostream& operator<<(std::ostream& os, const FrogPrince& rhs);
        //friend void Princess::marries(FrogPrince& betrothed);
    public:
        FrogPrince(const std::string& name);
        const std::string& getName() const;
        void setSpouse(Princess*);
    private:
        std::string name;
        Princess* spouse;
    };

}
#endif

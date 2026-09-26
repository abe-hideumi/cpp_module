#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <string>

class Brain {
    private:
        static const unsigned int   ideasCount = 100;

        std::string ideas[ideasCount];

    public:
        // constructors
        Brain();
        Brain(const Brain &other);
        Brain    &operator=(const Brain &other);
        ~Brain();

        // member functions
        const std::string &getIdea(unsigned int index) const;
        void setIdea(unsigned int index, const std::string &idea);
};

#endif

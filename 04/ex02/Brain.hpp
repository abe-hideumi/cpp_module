#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <string>

class Brain {
    private:
        std::string ideas[100];

    public:
        Brain();
        Brain(const Brain &other);
        Brain    &operator=(const Brain &other);
        ~Brain();

        const std::string &getIdea(unsigned int index) const;
        void setIdea(unsigned int index, const std::string &idea);
};

#endif

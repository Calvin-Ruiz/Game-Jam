/*
** EPITECH PROJECT, 2020
** Game-Jam
** File description:
** Core.hpp
*/

#ifndef CORE_HPP_
#define CORE_HPP_

#include "ThreadedModule.hpp"

class Core : public ThreadedModule {
public:
    Core();
    virtual ~Core();
    Core(const Core &cpy) = default;
    Core &operator=(const Core &src) = default;

    virtual void initalize() override;
    virtual void refresh() override;
private:

};

#endif /* CORE_HPP_ */

/**
  * This file is part of OVU.
  *
  * This program is free software: you can redistribute it and/or modify
  * it under the terms of the GNU General Public License as published by
  * the Free Software Foundation, either version 3 of the License, or
  * (at your option) any later version.
  *
  * This program is distributed in the hope that it will be useful,
  * but WITHOUT ANY WARRANTY; without even the implied warranty of
  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
  * GNU General Public License for more details.
  *
  * You should have received a copy of the GNU General Public License
  * along with this program. If not, see <http://www.gnu.org/licenses/>.
  *
  * Copyright (C) 2015 Mikhail Ivchenko <ematirov@gmail.com>
  *
  **/

#ifndef AUTHOR_ELEMENT_H
#define AUTHOR_ELEMENT_H

#include "Element.h"

#include "NameElement.h"

class AuthorElement : public Element
{

    Q_OBJECT

public:
    explicit AuthorElement(NameElement *name = new NameElement);
    ~AuthorElement();

    Element::ElementType type() const override;

    NameElement *name() const;
    void setName(NameElement *name);

private:
    NameElement *m_name;
};

#endif // AUTHOR_ELEMENT_H

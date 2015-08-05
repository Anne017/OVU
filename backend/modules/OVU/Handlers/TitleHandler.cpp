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

#include "TitleHandler.h"

#include "Elements/TitleElement.h"

TitleHandler::TitleHandler()
{
}

Element *TitleHandler::parse(QXmlStreamReader &reader) const
{
    Q_ASSERT(reader.isStartElement());
    QString value;
    QXmlStreamReader::TokenType currentToken = reader.readNext();
    while( !isEndElement(reader,QString("title")) && !reader.hasError() ) {
        if( currentToken == QXmlStreamReader::Characters ) {
            value+=reader.text();
        }
        currentToken = reader.readNext();
    }
    return new TitleElement(value);
}

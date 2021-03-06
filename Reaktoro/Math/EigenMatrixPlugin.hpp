// Reaktoro is a unified framework for modeling chemically reactive systems.
//
// Copyright (C) 2014-2018 Allan Leal
//
// This library is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public
// License as published by the Free Software Foundation; either
// version 2.1 of the License, or (at your option) any later version.
//
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
// Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public License
// along with this library. If not, see <http://www.gnu.org/licenses/>.

Matrix(const std::initializer_list<Scalar>& list)
: Matrix(list.size(), 1)
{
    Index i = 0;
    for(const auto& entry : list)
    {
        (*this).data()[i] = entry; ++i;
    }
}

Matrix(const std::initializer_list<std::initializer_list<Scalar>>& list)
: Matrix(list.size(), list.size() ? list.begin()->size() : 0)
{
    Index i = 0, j = 0;
    for(const auto& row : list)
    {
        for(const auto& entry : row)
        {
            (*this)(i, j) = entry; ++j;
        }
        j = 0; ++i;
    }
}

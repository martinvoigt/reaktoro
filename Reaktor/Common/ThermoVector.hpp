// Reaktor is a C++ library for computational reaction modelling.
//
// Copyright (C) 2014 Allan Leal
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program. If not, see <http://www.gnu.org/licenses/>.

#pragma once

// Reaktor includes
#include <Reaktor/Common/Matrix.hpp>

namespace Reaktor {

// Forward declarations
class ThermoScalar;
class ThermoVectorConstRow;
class ThermoVectorRow;

/// Describe the thermodynamic properties and their partial temperature and pressure
/// derivatives of a collection of species or reactions.
/// ingroup Common
class ThermoVector
{
public:
    /// Construct a ThermoVector instance with given dimension
    /// @param nrows The number of rows of the vector quantities
    ThermoVector(unsigned nrows);

    /// Construct a ThermoVector instance
    /// @param val The values of the thermodynamic properties
    /// @param ddt The partial temperature derivatives of the thermodynamic properties
    /// @param ddp The partial pressure derivatives of the thermodynamic properties
    ThermoVector(const Vector& val, const Vector& ddt, const Vector& ddp);

    /// Get a reference of a row of this ThermoVector instance
    auto row(unsigned irow) -> ThermoVectorRow;

    /// Get a const reference of a row of this ThermoVector instance
    auto row(unsigned irow) const -> ThermoVectorConstRow;

    /// The values of the thermodynamic properties
    Vector val;

    /// The partial temperature derivatives of the thermodynamic properties
    Vector ddt;

    /// The partial pressure derivatives of the thermodynamic properties
    Vector ddp;
};

/// An auxiliary type for the representation of the view of a row of a ThermoVector instance
class ThermoVectorRow
{
public:
    ThermoVectorRow(ThermoVector& vector, unsigned irow);
    auto operator=(const ThermoScalar& property) -> ThermoVectorRow&;
    double& val;
    double& ddt;
    double& ddp;
};

/// An auxiliary type for the representation of the const view of a row of a ThermoVector instance
class ThermoVectorConstRow
{
public:
    ThermoVectorConstRow(const ThermoVector& properties, unsigned irow);
    const double& val;
    const double& ddt;
    const double& ddp;
};

/// Compare two ThermoVector instances for equality
auto operator==(const ThermoVector& l, const ThermoVector& r) -> bool;

/// A type used to define the function signature for the calculation of many thermodynamic properties.
/// @see ThermoVector, ThermoScalar, ThermoScalarFunction
using ThermoVectorFunction = std::function<ThermoVector(double, double)>;

} // namespace Reaktor

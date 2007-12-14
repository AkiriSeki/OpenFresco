/* ****************************************************************** **
**    OpenFRESCO - Open Framework                                     **
**                 for Experimental Setup and Control                 **
**                                                                    **
**                                                                    **
** Copyright (c) 2006, Yoshikazu Takahashi, Kyoto University          **
** All rights reserved.                                               **
**                                                                    **
** Licensed under the modified BSD License (the "License");           **
** you may not use this file except in compliance with the License.   **
** You may obtain a copy of the License in main directory.            **
** Unless required by applicable law or agreed to in writing,         **
** software distributed under the License is distributed on an        **
** "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND,       **
** either express or implied. See the License for the specific        **
** language governing permissions and limitations under the License.  **
**                                                                    **
** Developed by:                                                      **
**   Yoshikazu Takahashi (yos@catfish.dpri.kyoto-u.ac.jp)             **
**   Andreas Schellenberg (andreas.schellenberg@gmx.net)              **
**   Gregory L. Fenves (fenves@berkeley.edu)                          **
**                                                                    **
** ****************************************************************** */

// $Revision$
// $Date$
// $URL: $

// Written: Yoshi
// Created: 09/06
// Revision: A
//
// Purpose: This file contains the implementation of 
// UndershootErrorFilter.

#include "UndershootErrorFilter.h"

#include <math.h>


UndershootErrorFilter::UndershootErrorFilter(int tag, double error)
    : ErrorFilter(tag),
    undershoot(error), data(0.0), predata(0.0)
{
    // does nothing
}


UndershootErrorFilter::UndershootErrorFilter(const UndershootErrorFilter& uef)
    : ErrorFilter(uef)
{
    undershoot = uef.undershoot;
    data = uef.data;
    predata = uef.predata;
}


UndershootErrorFilter::~UndershootErrorFilter()
{
    // does nothing
}


double UndershootErrorFilter::filtering(double d)
{
    data = d;
    if(d > predata) {
        data -= undershoot;
    } else if(d < predata) {
        data += undershoot;
    }
    if(fabs(d) < 1.0e-6) {
        data += undershoot;
    }
    //  opserr << "U : " << d << ", U_b = " << predata << ", err = " << d-data << endln;
    predata = d;
    
    return data;
}


void UndershootErrorFilter::update()
{
    // does nothing
}


SignalFilter* UndershootErrorFilter::getCopy()
{
    return new UndershootErrorFilter(*this);
}


void UndershootErrorFilter::Print(OPS_Stream &s, int flag =0)
{
    s << "Filter: " << this->getTag(); 
    s << " type: UndershootErrorFilter\n";
    s << "\tundershoot error = " << undershoot << endln;
}


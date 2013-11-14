/****************************************************************************
 Copyright (c) 2013 cocos2d-x.org
 
 http://www.cocos2d-x.org
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/

#include "../CCPhysicsSetting.h"
#if (CC_PHYSICS_ENGINE == CC_PHYSICS_CHIPMUNK)

#ifndef __CCPHYSICS_HELPER_H__
#define __CCPHYSICS_HELPER_H__

#include "chipmunk.h"
#include "platform/CCPlatformMacros.h"
#include "cocoa/CCGeometry.h"

NS_CC_BEGIN

class PhysicsHelper
{
public:
    static Point cpv2point(const cpVect& vec) { return Point(vec.x, vec.y); }
    static cpVect point2cpv(const Point& point) { return cpv(point.x, point.y); }
    static Size cpv2size(const cpVect& vec) { return Size(vec.x, vec.y); }
    static cpVect size2cpv(const Size& size) { return cpv(size.width, size.height); }
    static float cpfloat2float(cpFloat f) { return f; }
    static cpFloat float2cpfloat(float f) { return f; }
    static cpBB rect2cpbb(const Rect& rect) { return cpBBNew(rect.origin.x, rect.origin.y, rect.origin.x + rect.size.width, rect.origin.y + rect.size.height); }
    static Rect cpbb2rect(const cpBB& bb) { return Rect(bb.l, bb.b, bb.r, bb.t); }
    
    static Point* cpvs2points(const cpVect* cpvs, Point* points, int count)
    {
        for (int i = 0; i < count; ++i)
        {
            points[i] = cpv2point(cpvs[i]);
        }
        
        return points;
    }
    
    static cpVect* points2cpvs(const Point* points, cpVect* cpvs, int count)
    {
        for (int i = 0; i < count; ++i)
        {
            cpvs[i] = point2cpv(points[i]);
        }
        
        return cpvs;
    }
};

NS_CC_END
#endif // __CCPHYSICS_HELPER_H__

#endif // CC_PHYSICS_ENGINE == CC_PHYSICS_CHIPMUNK

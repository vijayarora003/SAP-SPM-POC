//
//  ParameterInstanceWrapper.h
//  SAPOfflineOData
//
//  Copyright © 2017 SAP SE or an SAP affiliate company. All rights reserved.
//
//  No part of this publication may be reproduced or transmitted in any form or for any purpose
//  without the express permission of SAP SE.  The information contained herein may be changed
//  without prior notice.
//

#import "MemoryTrackerBase.h"

#if __cplusplus

namespace lodata
{
    class ParameterInstance;
    class Parameter;
}

#endif


@class ArenaAllocatorWrapper;
@class ParameterWrapper;
@class ValueWrapper;
@class ComplexTypeWrapper;
@class ModifiedEntityTypeInstanceWrapper;


@interface ParameterInstanceWrapper : OBJ_WRAPPER_BASE

- ( instancetype ) init:(const ParameterWrapper*) parameter allocator: (ArenaAllocatorWrapper *) allocator;

- (void) setSimpleValue: (ValueWrapper *) value ;

- (void) setComplexValue: (ModifiedComplexTypeInstanceWrapper *) value ;

- (void) setEntityValue: (ModifiedEntityTypeInstanceWrapper *) value ;

#if __cplusplus
- (lodata::ParameterInstance *) getCppInstance;
#endif

@end

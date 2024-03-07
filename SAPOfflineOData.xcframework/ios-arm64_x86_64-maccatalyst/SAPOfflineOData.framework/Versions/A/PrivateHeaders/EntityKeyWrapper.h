//
//  EntityKeyWrapper.h
//  SAPOfflineOData
//
//  Copyright © 2023 SAP SE or an SAP affiliate company. All rights reserved.
//
//  No part of this publication may be reproduced or transmitted in any form or for any purpose
//  without the express permission of SAP SE.  The information contained herein may be changed
//  without prior notice.
//

#import "EnumerationDef.h"
#import "MemoryTrackerBase.h"

#if __cplusplus

namespace lodata
{
    class EntityKey;
}

#endif

typedef enum {
     SIMPLE_KEY = 0,
     COMPLEX_KEY = 1 ,
     NAVIGATION_KEY = 2
} EntityKeyKind;

@class EnumTypeWrapper;
@class ArenaAllocatorWrapper;

@interface EntityKeyWrapper :OBJ_WRAPPER_BASE

#if __cplusplus

- (instancetype) initWithCppInstance: (const lodata::EntityKey * ) cppEntityKey;

- (const lodata::EntityKey *) getCppInstance;

#endif

- (bool) isEnumKey;
- (EnumTypeWrapper *) getEnumType;
- (EntityKeyKind) getKeyKind;
- (EdmTypeObjC) getEdmType;

@end

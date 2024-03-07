//
//  CollectionItemTypeWrapper.h
//  SAPOfflineOData
//
//  Copyright © 2021 SAP SE or an SAP affiliate company. All rights reserved.
//
//  No part of this publication may be reproduced or transmitted in any form or for any purpose
//  without the express permission of SAP SE.  The information contained herein may be changed
//  without prior notice.
//

#import "StructuralTypeWrapper.h"
#import "ComplexTypeWrapper.h"
#import "EnumTypeWrapper.h"

#if __cplusplus

namespace lodata
{
    class CollectionItemType;
}

#endif

typedef enum {
        PRIMITIVE_KIND = 1,
        COMPLEX_KIND,
        ENUM_KIND
} ItemKind;

@interface CollectionItemTypeWrapper : OBJ_WRAPPER_BASE

#if __cplusplus

- (instancetype) initWithCppInstance: (const lodata::CollectionItemType * ) cppCollectionItemType;

- (const lodata::CollectionItemType *) getCppInstance;

#endif

- (ItemKind) getItemKind;

- (ComplexTypeWrapper*) getComplexTypeWrapper;

- (EnumTypeWrapper*) getEnumTypeWrapper;

@end

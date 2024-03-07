//
//  CollectionItemResultWrapper.h
//  SAPOfflineOData
//
//  Copyright © 2021 SAP SE or an SAP affiliate company. All rights reserved.
//
//  No part of this publication may be reproduced or transmitted in any form or for any purpose
//  without the express permission of SAP SE.  The information contained herein may be changed
//  without prior notice.
//

#import "MemoryTrackerBase.h"

#if __cplusplus
namespace lodata
{
    class CollectionItemResult;
}
#endif

@class CollectionTypePropertyWrapper;

@interface CollectionItemResultWrapper : OBJ_WRAPPER_BASE

#if __cplusplus
- ( instancetype ) initWithCppInstance: (const lodata::CollectionItemResult *) cppCollectionItemResult;
#endif

- ( CollectionTypePropertyWrapper * ) getCollectionTypePropertyWrapper;
- ( ComplexTypeInstanceWrapper* ) getComplexTypeInstanceWrapper;
- ( EnumValueWrapper * ) getEnumValueWrapper;
- ( ValueWrapper * ) getValueWrapper;
- ( CollectionItemTypeWrapper* ) getCollectionItemTypeWrapper;

@end

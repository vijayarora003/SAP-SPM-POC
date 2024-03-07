// swift-tools-version:5.5
// The swift-tools-version declares the minimum version of Swift required to build this package.

import PackageDescription

let package = Package(
    name: "SAP-SPM-POC",
    products: [
        .library(
            name: "SAP-SPM-POC",
            targets: ["SAPCommon",
                       "SAPFiori",
                       "SAPFioriFlows",
                       "SAPFoundation",
                       "SAPOData",
                       "SAPOfflineOData",]),
    ],
    dependencies: [],
    targets: [
        .binaryTarget(
            name: "SAPCommon",
            path: "SAPCommon.xcframework"
        ),
        .binaryTarget(
            name: "SAPFiori",
            path: "SAPFiori.xcframework"
        ),
        .binaryTarget(
            name: "SAPFioriFlows",
            path: "SAPFioriFlows.xcframework"
        ),
        .binaryTarget(
            name: "SAPFoundation",
            path: "SAPFoundation.xcframework"
        ),
        .binaryTarget(
            name: "SAPOData",
            path: "SAPOData.xcframework"
        ),
        .binaryTarget(
            name: "SAPOfflineOData",
            path: "SAPOfflineOData.xcframework"
        ),
        .target(
            name: "SAP-SPM-POC",
            dependencies: [
                "SAPCommon",
                "SAPFiori",
                "SAPFioriFlows",
                "SAPFoundation",
                "SAPOData",
                "SAPOfflineOData",
            ]
        )
    ]
)

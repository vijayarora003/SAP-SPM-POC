// swift-tools-version:5.5
// The swift-tools-version declares the minimum version of Swift required to build this package.

import PackageDescription

let package = Package(
    name: "SAP-SPM-POC",
    platforms: [.iOS(.v15)],
    products: [
        .library(
            name: "SAP-SPM-POC",
            targets: ["cloud-sdk-ios"]),
    ],
    dependencies: [
        .package(name: "cloud-sdk-ios", url: "https://github.com/SAP/cloud-sdk-ios.git", from: "9.2.7"),
    ],
    targets: [
        .target(
            name: "cloud-sdk-ios",
            dependencies: [
                .product(name: "SAPCommon", package: "cloud-sdk-ios"),
                .product(name: "SAPFiori", package: "cloud-sdk-ios"),
                .product(name: "SAPFioriFlows", package: "cloud-sdk-ios"),
                .product(name: "SAPFoundation", package: "cloud-sdk-ios"),
                .product(name: "SAPOData", package: "cloud-sdk-ios"),
                .product(name: "SAPOfflineOData", package: "cloud-sdk-ios"),
                .product(name: "SAPML", package: "cloud-sdk-ios"),
            ],
            path: "Sources"
        ),
    ]
)

plugins {
    id("com.android.application")
    id("org.jetbrains.kotlin.android") version "1.8.0"
}

android {
    namespace = "com.example.musicplayer" // 여기에 namespace 추가
    compileSdk = 34

    defaultConfig {
        applicationId = "com.example.musicplayer"
        minSdk = 21
        targetSdk = 33
        versionCode = 1
        versionName = "1.0"
    }

    buildTypes {
        getByName("release") {
            isMinifyEnabled = false
            proguardFiles(getDefaultProguardFile("proguard-android-optimize.txt"), "proguard-rules.pro")
        }
    }
}

dependencies {
    implementation("org.jetbrains.kotlin:kotlin-stdlib:1.9.10")
    implementation("androidx.core:core-ktx:1.9.0")
    implementation("androidx.appcompat:appcompat:1.5.1")
    implementation("com.google.android.material:material:1.7.0")
    implementation(libs.ext.junit)
    testImplementation("org.testng:testng:6.9.6")
    testImplementation("junit:junit:4.12")
    androidTestImplementation("junit:junit:4.12")
    androidTestImplementation("junit:junit:4.12")
    androidTestImplementation("junit:junit:4.12")

}







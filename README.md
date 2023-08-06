# Documentación de Become iOS SDK

Proceso de instalación de la librería become_IOS_SDK.

## Agregar Frameworks al proyecto
Se debe agregar la librería `BecomeDigitalV.framework` en las configuraciones generales del proyecto en la sección **framework, libraries, and embedded content**:

Para el correcto funcionamiento de la SDK, se requiere el uso del framework  `Microblink.xcframework`, el cual se deben adicionar en la sección **framework, libraries, and embedded content**:
 
 <p align="center">
  <img src="https://github.com/Becomedigital/become_IOS_SDK_Document_Authentication/blob/main/IMG_2.png">
</p>

## Configuraciones dentro de info.plist 

La SDK requiere que dentro de las configuraciones `info.plis`, se encuentre una descripción de uso de la cámara:

    Privacy - Camera Usage Description ( Esta aplicación hace uso de tu cámara)
    
 <p align="center">
  <img src="https://github.com/Becomedigital/become_IOS_SDK/blob/master/IMG_3.png">
 </p>
 
## Inicialización de la SDK

**1. Importar el SDK en nuestro viewController:**

        import  BecomeDigitalV


**2. En el método `startSDKAction ()` de su `ViewController` de aplicación, inicialice Become para la captura de imágenes, se debe asignar el `ItFirstTransaction` como True, puedes utilizar el siguiente fragmento de código:**
 
      @IBAction func startSDKAction(_ sender: Any) {
               let dateFormatter = DateFormatter()
               dateFormatter.locale = Locale(identifier: "es_ES") // date user identification
               dateFormatter.dateFormat = "yyyyMMddHHmmssSSS"
               userID = userId.text!.isEmpty ? dateFormatter.string(from: Date()) : userId.text!
               
               let bdivConfig = BDIVConfig(isFirstTransaction: true,
                                            enableRecognitionModeFilter: true, // default false: Filter for recognition of immigration documents that contain different types of QR codes on the back. 
                                              token:"your_bearer_token",
                                              contractId:  "your_contract_id",
                                              userId: userID,
                                              customLocalizationFileName: "localize_test")
                                              
               BDIVCallBack.sharedInstance.register(bdivConfig: bdivConfig)
       }
                    

**3. En el método `secondAction ()` de su `ViewController` de aplicación, inicialice Become y proceda al el envío de la imagen del documento para su posterior validación, se debe asignar el `ItFirstTransaction` como `False`, Y el parámetro `imgData` debe estar cargado con la información de la imagen completa por el anverso del documento. Puedes utilizar el siguiente fragmento de código:**

Nota: para obtener información de la registraduría nacional de Colombia, se requiere se adicione el parámetro `documentNumber`, el cual es retornado por el primer llamado a la SDK. 
 
     @IBAction func secondAction(_ sender: Any) {
        lblResponse.text = "Enviando segunda petición..."
       
       let bdivConfig = BDIVConfig(
              ItFirstTransaction: false,
              token: token.text!,
              contractId: (contractId.text!.isEmpty ? "2" : contractId.text)!,
              userId: userID,
              documentNumber: responseIV.documentNumber, // adicionar este parámetro si es documento colombiano.
              isoAlpha2CountryCode: responseIV.isoAlpha2CountryCode,
              type: responseIV.type.rawValue,
              imgDataFullFront: (responseIV.fullFronImage?.pngData())!,
              imgDataCroppetBack: (responseIV.backImage?.pngData())!,
              barcodeResultData: responseIV.barcodeResult)
              
        BDIVCallBack.sharedInstance.register(bdivConfig: bdivConfig)
    }
    
 
 ## Cambiar textos predeterminados en la SDK     

Para cambiar algún texto predeterminado y asignar uno en reemplazo de este, cree un archivo .string ejemplo: `localize_test.strings` en su proyecto y agrege la eqtiqueta del texto a remplazar ejemplo: `"blinkid_generic_message" = "Su texto aca";`, luego agregue el atributo `customLocalizationFileName` con el nombre del archivo strings en el objeto `BDIVConfig`.

Con `Localize_test.string.string` abierto, en el inspector de archivos toque el botón "Localizar..." y seleccione Inglés.

    @IBAction func startSDKAction(_ sender: Any) {
             let dateFormatter = DateFormatter()
             dateFormatter.locale = Locale(identifier: "es_ES") // date user identification
             dateFormatter.dateFormat = "yyyyMMddHHmmssSSS"
             userID = userId.text!.isEmpty ? dateFormatter.string(from: Date()) : userId.text!
             let bdivConfig = BDIVConfig(token:"your_bearer_token",
                               contractId:  "your_contract_id",
                               userId: userID,
                               ItFirstTransaction: true,
                               customLocalizationFileName: "localize_test")
             BDIVCallBack.sharedInstance.register(bdivConfig: bdivConfig)
     }
     
**Listado de llaves**

    "blinkid_generic_message" = "Escaneo de la parte frontal\nde un documento";
    "mb_blinkid_back_instructions_barcode" = "Escanea el código de barras";
    "mb_blinkid_camera_flip_document" = "Dele la vuelta al documento";
    "mb_blinkid_camera_high" = "Acercarse";
    "mb_blinkid_camera_near" = "Alejarse";
    "mb_blinkid_document_too_close_to_edge" = "Mueva el documento desde el borde";
    "mb_check_internet_connection" = "Verifique su conexión a Internet";
    "mb_close" = "Cerrar";
    "mb_data_not_match_msg" = "Por favor, inicie el proceso de escaneo de nuevo.";
    "mb_data_not_match_retry_button" = "Reintentar";
    "mb_data_not_match_title" = "Los lados no coinciden";
    "mb_error_mandatory_field_missing" = "Mantenga el documento visible en su totalidad";
    "mb_flashlight_glare_tooltip" = "Tenga cuidado con el resplandor de la linterna.\nMueva suavemente su ID a su alrededor para evitarlo.";
    "mb_network_error" = "Error de red";
    "mb_recognition_timeout_dialog_message" = "No se puede leer el documento. Por favor, inténtelo de nuevo.";
    "mb_recognition_timeout_dialog_title" = "Escaneo fallido";
    "mb_scanning_not_available" = "Escaneo no disponible";
    "mb_something_went_wrong" = "Algo ha ido mal";
    "mb_tooltip_glare" = "Mueva ligeramente la identificación para eliminar el deslumbramiento.";
    "mb_try_scanning_again" = "Parece que la información del documento no es consistente. Intente escanear de nuevo.";
    "mb_unsupported_document_message" = "Escanee la parte frontal de un documento compatible.";
    "mb_unsupported_document_title" = "Documento no reconocido";
    "photopay_align_message" = "Ponga el teléfono sobre el comprobante de pago";
    "photopay_back_splash_verification_document" = "Lado posterior";
    "photopay_back_verification_document" = "Ponga el lado trasero del documento en el marco y espere al que se haga el escaneo automático.";
    "photopay_camera_permission_denied" = "{font:@Medium}%@{/font} no tiene permiso para usar la cámara.\n\nVaya a:\n• {font:@Medium}Ajustes{/font}\n• {font:@Medium}%@{/font}\n• Asegúrese de que {font:@Medium}l la cámara{/font} esté activada";
    "photopay_close" = "Cancelar";
    "photopay_done_splash_verification_document" = "Escaneo del documento realizado";
    "photopay_front_splash_verification_document" = "Lado frontal";
    "photopay_front_verification_document" = "Ponga el lado delantero del documento en el marco y espere a que se haga el escaneo automático.";
    "photopay_grant_camera_permission_button_title" = "Otorgar permiso a la cámara";
    "photopay_id_position_tooltip" = "Ponga la tarjeta identificativa en este marco";


## Respuesta de la SDK 
**1. Estructura encargada de la definición del estado de validación exitoso:**

La SDK dará respuesta mediante dos métodos o promesas de respuesta, que pertenecen al estructura  `BDIVDelegate`:

    	func BDIVResponseSuccess(bdivResult: AnyObject) {       
    		        let idmResultFinal = bdivResult as! ResponseIV        
    		       print(String(describing: idmResultFinal))           
    	}        
    
    	func BDIVResponseError(error: String) { 
    	       print(error)   
    	 }

## Estructura para el retorno de la información

Los siguientes parámetros permiten el retorno de la información capturada por el sistema mediante la promesa de respuesta o evento `BDIVResponseSuccess`:

    func BDIVResponseSuccess(bdivResult: AnyObject) {       
    		   let responseIV = bdivResult as! ResponseIV        
    		   
          if(responseIV.IsFirstTransaction){
            btnSecont.isHidden = false
            lblResponse.text = String(describing: responseIV)
            self.imgFront.image = responseIV.frontImage
            self.imgBack.image = responseIV.backImage
            self.imgFullBack.image = responseIV.fullBackImage
            self.imgFullFront.image = responseIV.fullFronImage
        }else{
            lblResponse.text = String(describing: responseIV.documentValidation)
        }         
    }        

Si el parámetro `IsFirstTransaction`, es True, nos indica que es un retorna de la primera transacción, donde se obtiene la imágene que se debe enviar al segundo consumo.


## Objeto para el retorno de la información
Los siguientes parámetros permiten el retorno de la información capturada por el sistema:

      public enum typeEstatus {
        case SUCCES
        case ERROR
        case PENDING
        case NOFOUND
    }
    
    public var firstName: String
    public var lastName: String
    public var documentNumber: String
    public var dateOfIssue: Date
    public var dateOfExpiry: Date
    public var age: Int
    public var dateOfBirth: Date
    public var placeOfBirth: String
    public var nationality: String
    public var mrzText: String
    public var sex: String
    public var barcodeResult: String
    public var barcodeResultData: Data
    public var isoAlpha2CountryCode: String
    public var isoAlpha3CountryCode: String
    public var isoNumericCountryCode: String
    public var type: MBType
    public var countryName: String
    /// Returns a clipping of the photograph extracted from the document
    public var faceImage: UIImage?
    /// Returns a clipping of the document image
    public var frontImage: UIImage?
    /// Returns a clipping of the document image
    public var backImage: UIImage?
    /// Return full image of the document image
    public var fullFronImage: UIImage?
    /// Return full image of the document image
    public var fullBackImage: UIImage?
    public var message: String
    /// Returns the results of the document validation.
    /// - returns: `liveness_score`, `quality_score`, `liveness_probability`
    public var documentValidation: [String: Any]
    /// Returns information from the database for the specific country
    public var registryInformation: [String: Any]
    public var responseStatus: typeEstatus = .PENDING
    /// Defines if the response comes from the first transaction.
    public var IsFirstTransaction: Bool

## Posibles Errores
**1. Error con parámetros vacíos**
Los siguientes parámetros son necesarios para la activación de la SDK por lo tanto su valor no debe ser vacío.

Parámetro | Valor
------------ | -------------
contractID | String
userID  | String
ItFirstTransaction  | Bool

Mostrará el siguiente error por consola:

    parameters cannot be empty

## Implementación del proceso

Esta sección se encarga de proporcionar el fragmento de código para la implementación final del proceso:

          import UIKit
          import  BecomeDigitalV

              class ViewController: UIViewController {

                  override func viewDidLoad() {
                      super.viewDidLoad()
                  }

                  @IBAction func startSDKAction(_ sender: Any) {
                      let dateFormatter = DateFormatter()
                      dateFormatter.locale = Locale(identifier: "es_ES") // date user identification
                      dateFormatter.dateFormat = "yyyyMMddHHmmssSSS"
                      userID = userId.text!.isEmpty ? dateFormatter.string(from: Date()) : userId.text!
                      let bdivConfig = BDIVConfig(token:"your_bearer_token",
                                        contractId:  "your_contract_id",
                                        userId: userID,
                                        ItFirstTransaction: true)
                      BDIVCallBack.sharedInstance.register(bdivConfig: bdivConfig)
                  }
              }


              extension ViewController: BDIVDelegate{
                  func BDIVResponseSuccess(bdivResult: AnyObject) {
                      let idmResultFinal = bdivResult as! ResponseIV
                      print(String(describing: idmResultFinal))

                  }

                  func BDIVResponseError(error: String) {
                      print(error)
                  }
              }

## Requerimientos
•	Tecnologías
iOS 12 en adelante

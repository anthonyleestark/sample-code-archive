To use the Google Translate API, you need to enable the Cloud Translation API in your Google Cloud project and get an API key. You can use this key to make requests to the API endpoints. The endpoint for translating text is /language/translate/v2, where you can specify the text, the source language (optional), and the target language.

Here is a possible JavaScript function that implements this method:

// A function that sends a text to Google Translate API and returns the translation
function translateText(text, target) { 
// The API key obtained from Google Cloud 
const key = “<my api key>”;

// The URL for the API request 
const url = “https://translation.googleapis.com/language/translate/v2?key=” + key;

// The data for the API request 
const data = { q: text, target: target };

// Use fetch to make the API request and return a promise 
return fetch(url, { method: “POST”, headers: { “Content-Type”: “application/json” }, body: JSON.stringify(data) }) 
.then(response => { 
// Check if the response is ok 
if (response.ok) { 
// Parse the response as JSON 
return response.json(); 
} else { 
// Throw an error with the status code 
throw new Error(response.status); 
} 
}) 
.then(data => { 
// Extract the translation from the data 
const translation = data.data.translations[0].translatedText;

// Return the translation
return translation;
})
.catch(error => {
  // Handle the error
  console.error(error);
});
}

This function can be modified from the web search result #1 with some changes. You can also find more information about the Google Translate API in the web search results #2 and #3.